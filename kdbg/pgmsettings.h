/*
 * Copyright Johannes Sixt
 * This file is licensed under the GNU General Public License Version 2.
 * See the file COPYING in the toplevel directory of the source directory.
 */

#ifndef PGMSETTINGS_H
#define PGMSETTINGS_H

#include <KPageDialog>
#include "dbgdriver.h"

class QButtonGroup;
class QComboBox;
class QLabel;
class QLineEdit;


class ChooseDriver : public QWidget
{
    Q_OBJECT
public:
    ChooseDriver(QWidget* parent);
    void setDebuggerCmd(const QString& cmd);
    QString debuggerCmd() const;

    /*
     * Empty string (m_flavor) represents the Global Setting. So, in
     * setDisassemblyFlavor and disassemblyFlavor we are going to
     * "translate" to and from empty string and "Global Setting" with
     * a bunch of if's.
     */
    void setDisassemblyFlavor(const QString& flavor);
    QString disassemblyFlavor() const;

    void setIsX86(bool isX86);
protected:
    QLineEdit* m_debuggerCmd;
    QComboBox* m_disassComboBox;
};


class OutputSettings : public QWidget
{
    Q_OBJECT
public:
    OutputSettings(QWidget* parent);
    void setTTYLevel(int l);
    int ttyLevel() const { return m_ttyLevel; }
protected:
    int m_ttyLevel;
    QButtonGroup* m_group;
protected slots:
    void slotLevelChanged(int);
};


class ProgramSettings : public KPageDialog
{
    Q_OBJECT
public:
    ProgramSettings(QWidget* parent, QString exeName);

public:
    ChooseDriver m_chooseDriver;
    OutputSettings m_output;
};

#endif
