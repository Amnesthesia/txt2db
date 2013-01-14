/***************************************************************
 * Name:      MatrixDBMain.h
 * Purpose:   Defines Application Frame
 * Author:    Seminex ()
 * Created:   2012-12-01
 * Copyright: Seminex ()
 * License:
 **************************************************************/

#ifndef MATRIXDBMAIN_H
#define MATRIXDBMAIN_H

//(*Headers(MatrixDBDialog)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/filedlg.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/editlbox.h>
#include <wx/textdlg.h>
#include "include/FileProcessor.h"
//*)

class MatrixDBDialog: public wxDialog
{
    public:

        MatrixDBDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~MatrixDBDialog();

    private:

        //(*Handlers(MatrixDBDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OntabsPageChanged(wxNotebookEvent& event);
        void OnFileSelect(wxCommandEvent& event);
        void OnRun(wxCommandEvent& event);

        //*)

        //(*Identifiers(MatrixDBDialog)
        static const long ID_LISTCOLUMNS;
        static const long ID_BUTTONDELCOL;
        static const long ID_BUTTONADDCOL;
        static const long ID_LABELFILESEL;
        static const long ID_INPUTFILE;
        static const long ID_BUTTONKK;
        static const long ID_LABELDELIM;
        static const long ID_INPUTDELIM;
        static const long ID_PANEL1;
        static const long ID_PANEL2;
        static const long ID_TABS;
        static const long ID_BUTTONRUN;
        static const long ID_LABELTABLENAME;
        static const long ID_INPUTTABLENAME;
        //*)

        //(*Declarations(MatrixDBDialog)
        wxPanel* Panel1;
        wxEditableListBox* ListBox1;
        wxBoxSizer* outerWrapper;
        wxNotebook* tabs;
        wxTextCtrl* fileTextInput;
        wxStaticText* labelFileSelect;
        wxStaticText* labelTableName;
        wxPanel* Panel2;
        wxButton* fileButton;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* tableNameTextInput;
        wxStaticText* labelDelim;
        wxFileDialog* FileDialogue;
        wxButton* buttonRun;

        //*)

        wxString filePath;
        wxString fileName;

        DECLARE_EVENT_TABLE()
};

#endif // MATRIXDBMAIN_H
