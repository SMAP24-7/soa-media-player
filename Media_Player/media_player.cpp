#include "media_player.h"
#include "ui_media_player.h"

Media_Player::Media_Player(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Media_Player)
{
    ui->setupUi(this);

    connect(player, static_cast<void(QMediaPlayer::*)(QMediaPlayer::Error)>(&QMediaPlayer::error),
        [=](QMediaPlayer::Error error){

        if (error == 1){
            Qmessageerror.critical(0,"Error","Ha ocurrido un error crítico irrecuperable");
            Qmessageerror.setFixedSize(500,200);
            this->close();
        }
        else if (error == 2){
            Qmessageerror.critical(0,"Error","No se puede leer este formato");
            Qmessageerror.setFixedSize(500,200);
            Media_Player::on_Play_clicked();
        }
        else if(error == 4){
            Qmessageerror.critical(0,"Error","No tiene permisos para abrir ese archivo");
            Qmessageerror.setFixedSize(500,200);
            Media_Player::on_Play_clicked();
        }
        else if(error == 5){
            Qmessageerror.critical(0,"Error","No se puede reproducir");
            Qmessageerror.setFixedSize(500,200);
            Media_Player::on_Play_clicked();
        }


    });
    /*
    connect(o, &QMediaPlayer::error, [](QMediaPlayer::Error a) {
        cout << a;
    });
    */
}

Media_Player::~Media_Player()
{
    delete ui;
}

void Media_Player::on_Webcam_clicked()
{
    if (!player->state()){
        if (ui->Webcam->text() == "Iniciar Webcam"){
            camera->setViewfinder(ui->Video_display);
            camera->setCaptureMode(QCamera::CaptureVideo);
            camera->start();
            ui->Webcam->setText("Cerrar Webcam");
        }
        else if(ui->Webcam->text() == "Cerrar Webcam"){
            camera->stop();
            camera->unload();
            camera->setViewfinder(ui->Video_display);
            ui->Webcam->setText(("Iniciar Webcam"));
        }
    }
}

void Media_Player::on_Play_clicked()
{
    if  (ui->Webcam->text() == "Iniciar Webcam"){
         if(ui->Play->text() == "Play"){
             if (fileName.isNull()){
                fileName=QFileDialog::getOpenFileName(this, "Open File", QString(), "Text Files (*.mp4 *.avi)");
                player->setMedia(QUrl::fromLocalFile(fileName));
                player->setVideoOutput(ui->Video_display);
                ui->Video_display->show();
             }
             else if(fileName.isEmpty()){
                ui->Play->setText("Pause");
                player->play();
                v_reproduccion = 1.0;
                if(player->error()){
                    player->errorString();
                }
                //qDebug() << player->playbackRate();
             }
         }
         else if(ui->Play->text() == "Pause"){
             player->pause();
             ui->Play->setText("Play");
         }
         else if(ui->Play->text() == "V Normal"){
             player->pause();
             ui->Play->setText("Play");
         }
    }
}

void Media_Player::on_Stop_clicked()
{
    player->stop();
    fileName.clear();
    ui->Play->setText("Play");
}

void Media_Player::on_Rewind_clicked()
{
    v_reproduccion /=2;
    Set_Name_Speed_Button();
    Velocidad_Reproduccion();
    //qDebug() << player->playbackRate();
}

void Media_Player::on_Forwad_clicked()
{
    v_reproduccion *=2;
    Set_Name_Speed_Button();
    Velocidad_Reproduccion();
}

void Media_Player::Velocidad_Reproduccion()
{
    player->setPlaybackRate(v_reproduccion);
}

void Media_Player::Set_Name_Speed_Button()
{
    QString name;
    name.setNum( v_reproduccion*100/2);
    name += '%';
    ui->Rewind->setText("Forwad " +name);
    name.clear();
    name.setNum(v_reproduccion*100*2);
    name+= '%';
    ui->Forwad->setText("Rewind " + name);
}

