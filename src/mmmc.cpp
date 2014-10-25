#include "mmmc.h"
#include "music_model.h"
#include "song.h"

#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QTableView>
#include <QDockWidget>

#include <QMediaPlayer>
#include <QUrl>
#include <QAudioProbe>

#include <iostream>

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
    QString filename = QFileDialog::getOpenFileName(this, tr("Open a file caption"), "/home/harrigan/Music/", "Music file (*.wav *.mp3)");

    if (filename != "") {
        Song mySong(filename.toStdString());

    }

    QMediaPlayer * player = new QMediaPlayer();
    player->setMedia(QUrl::fromLocalFile(filename));

    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(updatePos(qint64)));

    player->play();

}

void mmmc::updatePos(qint64 position)
{
    std::cout<<"Called\t" << position << std::endl;
}



mmmc::~mmmc()
{}

#include "mmmc.moc"
