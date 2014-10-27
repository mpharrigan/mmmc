#include "mmmc.h"
#include "mainwidget.h"
#include "song.h"

#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QDockWidget>

#include <QDebug>

mmmc::mmmc()
{
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
}

void mmmc::createMenus() {
    qDebug() << "Making menus";
  
    // New
    QAction* newAction = new QAction(this);
    newAction->setText(tr("&New"));

    // Open
    QAction* openAction = new QAction(this);
    openAction->setText(tr("&Open"));
    connect(openAction, SIGNAL(triggered()), SLOT(open()));

    // Quit
    QAction* quitAction = new QAction(this);
    quitAction->setText(tr("&Quit"));
    connect(quitAction, SIGNAL(triggered()), SLOT(close()));

    // Create Menu
    QMenu* fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAction);

    // Load directory
    QAction* loadDirectoryMenu = new QAction(tr("Load Directory"), this);
    connect(loadDirectoryMenu, SIGNAL(triggered(bool)), this, SLOT(loadDirectory()));

    QMenu* libraryMenu = menuBar()->addMenu(tr("&Library"));
    libraryMenu->addAction(loadDirectoryMenu);
}

void mmmc::open()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open a file caption"), "/home/harrigan/Music/", "Music file (*.wav *.mp3)");

    if (filename != "") {
        Song mySong(filename);
	mainWidget->play(filename);
    }    
}

void mmmc::loadDirectory()
{
    Library * lib = Library::fromDirectory("/home/harrigan/Music/newcd/");
    mainWidget->tableModel->setLibrary(lib);
}

mmmc::~mmmc()
{}

#include "mmmc.moc"
