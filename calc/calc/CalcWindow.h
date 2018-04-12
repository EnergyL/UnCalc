#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CalcWindow.h"

class CalcWindow : public QMainWindow
{
	Q_OBJECT

public:
	CalcWindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::CalcWindowClass ui;
};
