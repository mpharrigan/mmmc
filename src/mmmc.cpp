#include "mmmc.h"
#include "mainwidget.h"
#include "song.h"

#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QDockWidget>
#include <QSettings>

#include <QDebug>

mmmc::mmmc() {
    // Center
    mainWidget = new MainWidget;
    setCentralWidget(mainWidget);

    // Right
    QDockWidget * rightDock = new QDockWidget(tr("Playlist"), this);
    rightDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    QLabel * placeholderLabel = new QLabel(tr("Placeholder"), rightDock);
    rightDock->setWidget(placeholderLabel);
    addDockWidget(Qt::RightDockWidgetArea, rightDock);

    // Menus
    createMenus();

    settingsDialog = 0;
}

void mmmc::createMenus() {
    qDebug() << "Making menus";

    // File -> New
    QAction * newAction = new QAction(this);
    newAction->setText(tr("&New"));

    // File -> Open
    QAction * openAction = new QAction(this);
    openAction->setText(tr("&Open"));
    connect(openAction, SIGNAL(triggered()), SLOT(open()));

    // File -> Quit
    QAction * quitAction = new QAction(this);
    quitAction->setText(tr("&Quit"));
    connect(quitAction, SIGNAL(triggered()), SLOT(close()));

    // File
    QMenu * fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAction);

    // Library -> Load directory
    QAction * loadDirectoryMenu = new QAction(tr("Load Directory"), this);
    connect(loadDirectoryMenu, SIGNAL(triggered(bool)), this, SLOT(loadDirectory()));

    // Library -> Settings
    QAction * settingsMenu = new QAction(tr("&Settings"), this);
    connect(settingsMenu, SIGNAL(triggered(bool)), this, SLOT(showSettings()));

    // Library
    QMenu * libraryMenu = menuBar()->addMenu(tr("&Library"));
    libraryMenu->addAction(loadDirectoryMenu);
    libraryMenu->addSeparator();
    libraryMenu->addAction(settingsMenu);
}

void mmmc::open() {
    QString filename = QFileDialog::getOpenFileName(this, tr("Open a file caption"), "/home/harrigan/Music/", "Music file (*.wav *.mp3)");

    if (filename != "") {
        Song mySong(filename);
        mainWidget->play(filename);
    }
}

void mmmc::loadDirectory() {
    QSettings settings;
    QString libdir = settings.value("library/directory", "~/Music/").toString();
    Library * lib = Library::fromDirectory(libdir);
    mainWidget->tableModel->setLibrary(lib);
}

void mmmc::showSettings() {
    if (!settingsDialog) {
        settingsDialog = new SettingsDialog(this);
    }
    settingsDialog->show();
    settingsDialog->raise();
    settingsDialog->activateWindow();
}


mmmc::~mmmc()
{}

#include "mmmc.moc"
