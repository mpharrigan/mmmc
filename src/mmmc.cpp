#include "mmmc.h"
#include "music_model.h"

#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QAction>
#include <QtGui/QFileDialog>
#include <QtGui/QVBoxLayout>
#include <QtGui/QTableView>
#include <QtGui/QDockWidget>

mmmc::mmmc()
{
    resize(1000,500);

    QTableView * tableView = new QTableView(this);
    MusicModel * tableModel = new MusicModel;
    tableView->setModel(tableModel);
    setCentralWidget(tableView);

    // Right
    QDockWidget * rightDock = new QDockWidget(tr("Playlist"), this);
    rightDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    QLabel * placeholderLabel = new QLabel(tr("Placeholder"), rightDock);
    rightDock->setWidget(placeholderLabel);
    addDockWidget(Qt::RightDockWidgetArea, rightDock);

    createMenus();
}

void mmmc::createMenus() {
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
}

void mmmc::open()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open a file caption"), "", "Music file (*.wav *.mp3)");

    if (filename != "") {
      // TODO: This is gone
        //mainLabel->setText(filename);
    }
}


mmmc::~mmmc()
{}

#include "mmmc.moc"
