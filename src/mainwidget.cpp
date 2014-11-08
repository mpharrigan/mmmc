
#include "mainwidget.h"
#include "music_model.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableView>
#include <QHeaderView>

#include <QMediaPlayer>
#include <QUrl>
#include <QAudioProbe>

#include <QDebug>

MainWidget::MainWidget(QWidget * parent, Qt::WindowFlags f): QWidget(parent, f) {
    // Table
    QTableView * tableView = new QTableView;
    tableModel = new MusicModel;
    tableView->setModel(tableModel);
    tableView->horizontalHeader()->setDefaultSectionSize(300);
    tableView->horizontalHeader()->setStretchLastSection(true);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(tableView, SIGNAL(doubleClicked(QModelIndex)),
            this, SLOT(doubleClickRow(QModelIndex)));

    // Slider
    slider = new QSlider;
    slider->setOrientation(Qt::Horizontal);
    slider->setTickPosition(QSlider::NoTicks);
    slider->setMinimum(0);
    slider->setMaximum(1);
    slider->setValue(0);

    // Buttons
    playButton = new QPushButton("Play");

    // Bottom horizonal layout
    QHBoxLayout * botLayout = new QHBoxLayout;
    botLayout->addWidget(playButton);
    botLayout->addWidget(slider);

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(tableView, 1);
    layout->addLayout(botLayout);
    setLayout(layout);
}

QSize MainWidget::sizeHint() const {
    return QSize(1000, 600);
}

void MainWidget::doubleClickRow(const QModelIndex & index) {
    qDebug() << "Double click" << index;
    Song s = tableModel->getSong(index);
    play(s);
}

void MainWidget::play(const Song & song) {
    this->play(song.filename);
}

void MainWidget::play(const QString & filename) {
    QMediaPlayer * player = new QMediaPlayer();
    player->setMedia(QUrl::fromLocalFile(filename));

    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(updatePos(qint64)));
    connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(updateMax(qint64)));

    player->play();
    playButton->setText("Pause");
}

void MainWidget::updateMax(qint64 value) {
    qDebug() << "Setting maximum slider position" << value;
    slider->setMaximum(value);
}

void MainWidget::updatePos(qint64 value) {
    slider->setValue(value);
}



#include "mainwidget.moc"
