/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *icon;
    QTextBrowser *text;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *B;
    QPushButton *X;
    QPushButton *O;
    QPushButton *I;
    QPushButton *T;
    QPushButton *J;
    QPushButton *G;
    QPushButton *V;
    QPushButton *Z;
    QPushButton *A;
    QPushButton *C;
    QPushButton *W;
    QPushButton *R;
    QPushButton *D;
    QPushButton *F;
    QPushButton *P;
    QPushButton *H;
    QPushButton *S;
    QPushButton *M;
    QPushButton *L;
    QPushButton *K;
    QPushButton *E;
    QPushButton *U;
    QPushButton *Q;
    QPushButton *Y;
    QPushButton *N;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        icon = new QLabel(Widget);
        icon->setObjectName(QString::fromUtf8("icon"));
        icon->setGeometry(QRect(160, 20, 631, 341));
        text = new QTextBrowser(Widget);
        text->setObjectName(QString::fromUtf8("text"));
        text->setGeometry(QRect(150, 390, 641, 201));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 131, 581));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        B = new QPushButton(layoutWidget);
        B->setObjectName(QString::fromUtf8("B"));

        gridLayout->addWidget(B, 2, 0, 1, 1);

        X = new QPushButton(layoutWidget);
        X->setObjectName(QString::fromUtf8("X"));

        gridLayout->addWidget(X, 15, 1, 1, 1);

        O = new QPushButton(layoutWidget);
        O->setObjectName(QString::fromUtf8("O"));

        gridLayout->addWidget(O, 2, 1, 1, 1);

        I = new QPushButton(layoutWidget);
        I->setObjectName(QString::fromUtf8("I"));

        gridLayout->addWidget(I, 11, 0, 1, 1);

        T = new QPushButton(layoutWidget);
        T->setObjectName(QString::fromUtf8("T"));

        gridLayout->addWidget(T, 9, 1, 1, 1);

        J = new QPushButton(layoutWidget);
        J->setObjectName(QString::fromUtf8("J"));

        gridLayout->addWidget(J, 14, 0, 1, 1);

        G = new QPushButton(layoutWidget);
        G->setObjectName(QString::fromUtf8("G"));

        gridLayout->addWidget(G, 9, 0, 1, 1);

        V = new QPushButton(layoutWidget);
        V->setObjectName(QString::fromUtf8("V"));

        gridLayout->addWidget(V, 11, 1, 1, 1);

        Z = new QPushButton(layoutWidget);
        Z->setObjectName(QString::fromUtf8("Z"));

        gridLayout->addWidget(Z, 18, 1, 1, 1);

        A = new QPushButton(layoutWidget);
        A->setObjectName(QString::fromUtf8("A"));

        gridLayout->addWidget(A, 1, 0, 1, 1);

        C = new QPushButton(layoutWidget);
        C->setObjectName(QString::fromUtf8("C"));

        gridLayout->addWidget(C, 3, 0, 1, 1);

        W = new QPushButton(layoutWidget);
        W->setObjectName(QString::fromUtf8("W"));

        gridLayout->addWidget(W, 14, 1, 1, 1);

        R = new QPushButton(layoutWidget);
        R->setObjectName(QString::fromUtf8("R"));

        gridLayout->addWidget(R, 6, 1, 1, 1);

        D = new QPushButton(layoutWidget);
        D->setObjectName(QString::fromUtf8("D"));

        gridLayout->addWidget(D, 4, 0, 1, 1);

        F = new QPushButton(layoutWidget);
        F->setObjectName(QString::fromUtf8("F"));

        gridLayout->addWidget(F, 7, 0, 1, 1);

        P = new QPushButton(layoutWidget);
        P->setObjectName(QString::fromUtf8("P"));

        gridLayout->addWidget(P, 3, 1, 1, 1);

        H = new QPushButton(layoutWidget);
        H->setObjectName(QString::fromUtf8("H"));

        gridLayout->addWidget(H, 10, 0, 1, 1);

        S = new QPushButton(layoutWidget);
        S->setObjectName(QString::fromUtf8("S"));

        gridLayout->addWidget(S, 7, 1, 1, 1);

        M = new QPushButton(layoutWidget);
        M->setObjectName(QString::fromUtf8("M"));

        gridLayout->addWidget(M, 18, 0, 1, 1);

        L = new QPushButton(layoutWidget);
        L->setObjectName(QString::fromUtf8("L"));

        gridLayout->addWidget(L, 17, 0, 1, 1);

        K = new QPushButton(layoutWidget);
        K->setObjectName(QString::fromUtf8("K"));

        gridLayout->addWidget(K, 15, 0, 1, 1);

        E = new QPushButton(layoutWidget);
        E->setObjectName(QString::fromUtf8("E"));

        gridLayout->addWidget(E, 6, 0, 1, 1);

        U = new QPushButton(layoutWidget);
        U->setObjectName(QString::fromUtf8("U"));

        gridLayout->addWidget(U, 10, 1, 1, 1);

        Q = new QPushButton(layoutWidget);
        Q->setObjectName(QString::fromUtf8("Q"));

        gridLayout->addWidget(Q, 4, 1, 1, 1);

        Y = new QPushButton(layoutWidget);
        Y->setObjectName(QString::fromUtf8("Y"));

        gridLayout->addWidget(Y, 17, 1, 1, 1);

        N = new QPushButton(layoutWidget);
        N->setObjectName(QString::fromUtf8("N"));

        gridLayout->addWidget(N, 1, 1, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        icon->setText(QString());
        B->setText(QCoreApplication::translate("Widget", "B", nullptr));
        X->setText(QCoreApplication::translate("Widget", "X", nullptr));
        O->setText(QCoreApplication::translate("Widget", "O", nullptr));
        I->setText(QCoreApplication::translate("Widget", "I", nullptr));
        T->setText(QCoreApplication::translate("Widget", "T", nullptr));
        J->setText(QCoreApplication::translate("Widget", "J", nullptr));
        G->setText(QCoreApplication::translate("Widget", "G", nullptr));
        V->setText(QCoreApplication::translate("Widget", "V", nullptr));
        Z->setText(QCoreApplication::translate("Widget", "Z", nullptr));
        A->setText(QCoreApplication::translate("Widget", "A", nullptr));
        C->setText(QCoreApplication::translate("Widget", "C", nullptr));
        W->setText(QCoreApplication::translate("Widget", "W", nullptr));
        R->setText(QCoreApplication::translate("Widget", "R", nullptr));
        D->setText(QCoreApplication::translate("Widget", "D", nullptr));
        F->setText(QCoreApplication::translate("Widget", "F", nullptr));
        P->setText(QCoreApplication::translate("Widget", "P", nullptr));
        H->setText(QCoreApplication::translate("Widget", "H", nullptr));
        S->setText(QCoreApplication::translate("Widget", "S", nullptr));
        M->setText(QCoreApplication::translate("Widget", "M", nullptr));
        L->setText(QCoreApplication::translate("Widget", "L", nullptr));
        K->setText(QCoreApplication::translate("Widget", "K", nullptr));
        E->setText(QCoreApplication::translate("Widget", "E", nullptr));
        U->setText(QCoreApplication::translate("Widget", "U", nullptr));
        Q->setText(QCoreApplication::translate("Widget", "Q", nullptr));
        Y->setText(QCoreApplication::translate("Widget", "Y", nullptr));
        N->setText(QCoreApplication::translate("Widget", "N", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
