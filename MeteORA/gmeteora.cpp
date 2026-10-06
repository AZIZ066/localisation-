
#include "gmeteora.h"

#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QMessageBox>
#include <QDoubleValidator>
#include <QIntValidator>
#include <QAbstractItemView>
#include <QWidget>
#include <QTableWidgetItem>
#include <QFrame>

GMeteORA::GMeteORA(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("MeteORA - Gestion des localisations");
    resize(950, 650);

    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    central->setStyleSheet(
        "QWidget { background-color: #F4F7FB; }"
        "QLabel { color: #243247; font-size: 14px; }"
        "QLineEdit { background: white; border: 1px solid #CCD5E0;"
        "border-radius: 5px; padding: 8px; }"
        "QTableWidget { background: white; border: 1px solid #D9E1EA;"
        "gridline-color: #E5EAF0; }"
        "QHeaderView::section { background: #1769AA; color: white;"
        "padding: 9px; font-weight: bold; border: none; }"
        );

    QLabel *titre = new QLabel("GESTION DES LOCALISATIONS");
    titre->setAlignment(Qt::AlignCenter);
    titre->setStyleSheet(
        "font-size: 24px; font-weight: bold;"
        "color: #1769AA; padding: 15px;"
        );

    QLabel *sousTitre = new QLabel(
        "Smart Weather Management - MeteORA"
        );
    sousTitre->setAlignment(Qt::AlignCenter);
    sousTitre->setStyleSheet("color: #65758B; padding-bottom: 12px;");

    idEdit = new QLineEdit;
    villeEdit = new QLineEdit;
    latitudeEdit = new QLineEdit;
    longitudeEdit = new QLineEdit;
    rechercheEdit = new QLineEdit;

    idEdit->setPlaceholderText("Ex : 1");
    villeEdit->setPlaceholderText("Ex : Tunis");
    latitudeEdit->setPlaceholderText("Ex : 36.8065");
    longitudeEdit->setPlaceholderText("Ex : 10.1815");
    rechercheEdit->setPlaceholderText("Saisir le nom d'une ville...");

    idEdit->setValidator(
        new QIntValidator(1, 999999, idEdit)
        );

    auto *latValidator =
        new QDoubleValidator(-90.0, 90.0, 6, latitudeEdit);
    latValidator->setNotation(QDoubleValidator::StandardNotation);
    latitudeEdit->setValidator(latValidator);

    auto *lonValidator =
        new QDoubleValidator(-180.0, 180.0, 6, longitudeEdit);
    lonValidator->setNotation(QDoubleValidator::StandardNotation);
    longitudeEdit->setValidator(lonValidator);

    QFrame *formFrame = new QFrame;
    formFrame->setStyleSheet(
        "QFrame { background: white; border: 1px solid #D9E1EA;"
        "border-radius: 8px; }"
        );

    QFormLayout *form = new QFormLayout(formFrame);
    form->setContentsMargins(15, 15, 15, 15);
    form->setSpacing(12);
    form->addRow("ID :", idEdit);
    form->addRow("Ville :", villeEdit);
    form->addRow("Latitude :", latitudeEdit);
    form->addRow("Longitude :", longitudeEdit);

    ajouterBtn = new QPushButton("Ajouter");
    modifierBtn = new QPushButton("Modifier");
    supprimerBtn = new QPushButton("Supprimer");
    viderBtn = new QPushButton("Vider les champs");

    ajouterBtn->setStyleSheet(
        "QPushButton { background: #198754; color: white;"
        "padding: 10px; border-radius: 5px; font-weight: bold; }"
        "QPushButton:hover { background: #146C43; }"
        );

    modifierBtn->setStyleSheet(
        "QPushButton { background: #E9A23B; color: white;"
        "padding: 10px; border-radius: 5px; font-weight: bold; }"
        "QPushButton:hover { background: #CA8524; }"
        );

    supprimerBtn->setStyleSheet(
        "QPushButton { background: #DC3545; color: white;"
        "padding: 10px; border-radius: 5px; font-weight: bold; }"
        "QPushButton:hover { background: #B02A37; }"
        );

    viderBtn->setStyleSheet(
        "QPushButton { background: #64748B; color: white;"
        "padding: 10px; border-radius: 5px; }"
        "QPushButton:hover { background: #475569; }"
        );

    QHBoxLayout *boutons = new QHBoxLayout;
    boutons->addWidget(ajouterBtn);
    boutons->addWidget(modifierBtn);
    boutons->addWidget(supprimerBtn);
    boutons->addWidget(viderBtn);

    QLabel *tableTitre = new QLabel("Liste des localisations");
    tableTitre->setStyleSheet(
        "font-size: 17px; font-weight: bold;"
        "color: #243247; padding-top: 10px;"
        );

    table = new QTableWidget(0, 4);
    table->setHorizontalHeaderLabels(
        {"ID", "Ville", "Latitude", "Longitude"}
        );

    table->horizontalHeader()->setSectionResizeMode(
        QHeaderView::Stretch
        );

    table->setSelectionBehavior(
        QAbstractItemView::SelectRows
        );

    table->setSelectionMode(
        QAbstractItemView::SingleSelection
        );

    table->setEditTriggers(
        QAbstractItemView::NoEditTriggers
        );

    table->setAlternatingRowColors(true);
    table->verticalHeader()->setVisible(false);
    table->setMinimumHeight(220);

    QHBoxLayout *rechercheLayout = new QHBoxLayout;
    rechercheLayout->addWidget(new QLabel("Rechercher :"));
    rechercheLayout->addWidget(rechercheEdit);

    QVBoxLayout *layout = new QVBoxLayout(central);
    layout->setContentsMargins(22, 15, 22, 22);
    layout->setSpacing(12);

    layout->addWidget(titre);
    layout->addWidget(sousTitre);
    layout->addWidget(formFrame);
    layout->addLayout(boutons);
    layout->addWidget(tableTitre);
    layout->addLayout(rechercheLayout);
    layout->addWidget(table);

    connect(ajouterBtn, &QPushButton::clicked,
            this, &GMeteORA::ajouter);

    connect(modifierBtn, &QPushButton::clicked,
            this, &GMeteORA::modifier);

    connect(supprimerBtn, &QPushButton::clicked,
            this, &GMeteORA::supprimer);

    connect(viderBtn, &QPushButton::clicked,
            this, &GMeteORA::vider);

    connect(rechercheEdit, &QLineEdit::textChanged,
            this, &GMeteORA::rechercher);

    connect(table, &QTableWidget::cellClicked,
            this, &GMeteORA::selectionnerLigne);
}

GMeteORA::~GMeteORA() = default;

void GMeteORA::ajouter()
{
    if (idEdit->text().isEmpty() ||
        villeEdit->text().trimmed().isEmpty() ||
        latitudeEdit->text().isEmpty() ||
        longitudeEdit->text().isEmpty()) {
        QMessageBox::warning(
            this, "Erreur", "Veuillez remplir tous les champs."
            );
        return;
    }

    for (int i = 0; i < table->rowCount(); ++i) {
        if (table->item(i, 0)->text() == idEdit->text()) {
            QMessageBox::warning(
                this, "Erreur", "Cet ID existe déjà."
                );
            return;
        }
    }

    int row = table->rowCount();
    table->insertRow(row);

    table->setItem(row, 0,
                   new QTableWidgetItem(idEdit->text()));

    table->setItem(row, 1,
                   new QTableWidgetItem(villeEdit->text().trimmed()));

    table->setItem(row, 2,
                   new QTableWidgetItem(latitudeEdit->text()));

    table->setItem(row, 3,
                   new QTableWidgetItem(longitudeEdit->text()));

    vider();
}

void GMeteORA::modifier()
{
    int row = table->currentRow();

    if (row < 0) {
        QMessageBox::warning(
            this, "Erreur", "Sélectionnez une ligne à modifier."
            );
        return;
    }

    if (idEdit->text().isEmpty() ||
        villeEdit->text().trimmed().isEmpty() ||
        latitudeEdit->text().isEmpty() ||
        longitudeEdit->text().isEmpty()) {
        QMessageBox::warning(
            this, "Erreur", "Veuillez remplir tous les champs."
            );
        return;
    }

    for (int i = 0; i < table->rowCount(); ++i) {
        if (i != row &&
            table->item(i, 0)->text() == idEdit->text()) {
            QMessageBox::warning(
                this, "Erreur", "Cet ID existe déjà."
                );
            return;
        }
    }

    table->item(row, 0)->setText(idEdit->text());
    table->item(row, 1)->setText(villeEdit->text().trimmed());
    table->item(row, 2)->setText(latitudeEdit->text());
    table->item(row, 3)->setText(longitudeEdit->text());

    vider();
}

void GMeteORA::supprimer()
{
    int row = table->currentRow();

    if (row < 0) {
        QMessageBox::warning(
            this, "Erreur", "Sélectionnez une ligne à supprimer."
            );
        return;
    }

    QMessageBox::StandardButton reponse =
        QMessageBox::question(
            this,
            "Confirmation",
            "Voulez-vous supprimer cette localisation ?",
            QMessageBox::Yes | QMessageBox::No
            );

    if (reponse == QMessageBox::Yes)
        table->removeRow(row);

    vider();
}

void GMeteORA::vider()
{
    idEdit->clear();
    villeEdit->clear();
    latitudeEdit->clear();
    longitudeEdit->clear();
    table->clearSelection();
}

void GMeteORA::rechercher(const QString &texte)
{
    for (int i = 0; i < table->rowCount(); ++i) {
        bool visible = table->item(i, 1)->text().contains(
            texte.trimmed(), Qt::CaseInsensitive
            );

        table->setRowHidden(i, !visible);
    }
}

void GMeteORA::selectionnerLigne(int row, int column)
{
    Q_UNUSED(column);

    idEdit->setText(table->item(row, 0)->text());
    villeEdit->setText(table->item(row, 1)->text());
    latitudeEdit->setText(table->item(row, 2)->text());
    longitudeEdit->setText(table->item(row, 3)->text());
}