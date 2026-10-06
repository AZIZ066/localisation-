
#ifndef GMETEORA_H
#define GMETEORA_H

#include <QMainWindow>

class QLineEdit;
class QPushButton;
class QTableWidget;

class GMeteORA : public QMainWindow
{
    Q_OBJECT

public:
    explicit GMeteORA(QWidget *parent = nullptr);
    ~GMeteORA();

private:
    QLineEdit *idEdit;
    QLineEdit *villeEdit;
    QLineEdit *latitudeEdit;
    QLineEdit *longitudeEdit;
    QLineEdit *rechercheEdit;

    QTableWidget *table;

    QPushButton *ajouterBtn;
    QPushButton *modifierBtn;
    QPushButton *supprimerBtn;
    QPushButton *viderBtn;

    void ajouter();
    void modifier();
    void supprimer();
    void vider();
    void rechercher(const QString &texte);
    void selectionnerLigne(int row, int column);
};

#endif