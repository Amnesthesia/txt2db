/***************************************************************
 * Name:      MatrixDBMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Seminex ()
 * Created:   2012-12-01
 * Copyright: Seminex ()
 * License:
 **************************************************************/

#include "MatrixDBMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(MatrixDBDialog)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(MatrixDBDialog)
const long MatrixDBDialog::ID_LISTCOLUMNS = wxNewId();
const long MatrixDBDialog::ID_BUTTONDELCOL = wxNewId();
const long MatrixDBDialog::ID_BUTTONADDCOL = wxNewId();
const long MatrixDBDialog::ID_LABELFILESEL = wxNewId();
const long MatrixDBDialog::ID_INPUTFILE = wxNewId();
const long MatrixDBDialog::ID_BUTTONKK = wxNewId();
const long MatrixDBDialog::ID_LABELDELIM = wxNewId();
const long MatrixDBDialog::ID_INPUTDELIM = wxNewId();
const long MatrixDBDialog::ID_PANEL1 = wxNewId();
const long MatrixDBDialog::ID_PANEL2 = wxNewId();
const long MatrixDBDialog::ID_TABS = wxNewId();
const long MatrixDBDialog::ID_BUTTONRUN = wxNewId();
const long MatrixDBDialog::ID_INPUTTABLENAME = wxNewId();
const long MatrixDBDialog::ID_LABELTABLENAME = wxNewId();
//*)

BEGIN_EVENT_TABLE(MatrixDBDialog,wxDialog)
    //(*EventTable(MatrixDBDialog)
    //*)
END_EVENT_TABLE()

MatrixDBDialog::MatrixDBDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(MatrixDBDialog)
    wxBoxSizer* buttonSizer;
    wxGridSizer* GridSizer1;
    wxGridSizer* dbWrapper;
    wxBoxSizer* contentSizer;
    wxBoxSizer* filesWrapper;
    wxBoxSizer* wrapperSizer;
    wxStaticBoxSizer* columnWrapper;
    wxBoxSizer* addRemoveColumnWrapper;

    Create(parent, wxID_ANY, _("YO MATRIX HOW U LYK THIS UI? YEH? LYK IT M8? KTHX"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));

    // Set up sizers
    outerWrapper = new wxBoxSizer(wxVERTICAL);
    contentSizer = new wxBoxSizer(wxHORIZONTAL);
    columnWrapper = new wxStaticBoxSizer(wxVERTICAL, this, _("Table Columns"));
    filesWrapper = new wxBoxSizer(wxVERTICAL);
    buttonSizer = new wxBoxSizer(wxHORIZONTAL);


    GridSizer1 = new wxGridSizer(0, 3, 0, 0);
    dbWrapper = new wxGridSizer(0,2,0,0);
    wrapperSizer = new wxBoxSizer(wxVERTICAL);
    tabs = new wxNotebook(this, ID_TABS, wxDefaultPosition, wxSize(300,300), 0, _T("ID_TABS"));
    ListBox1 = new wxEditableListBox(this, ID_LISTCOLUMNS, wxT("Columns"), wxDefaultPosition, wxSize(150,300), wxEL_DEFAULT_STYLE, _T("ID_LISTCOLUMNS"));

    Panel1 = new wxPanel(tabs, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel2 = new wxPanel(tabs, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));

    // Structure sizers - fill 'em up


    wrapperSizer->Add(tabs, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    contentSizer->Add(wrapperSizer, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    outerWrapper->Add(contentSizer, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    contentSizer->Add(columnWrapper, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    columnWrapper->Add(ListBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    filesWrapper->Add(GridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);


    // Create our controls
    // Labels
    labelFileSelect = new wxStaticText(Panel1, ID_LABELFILESEL, _("File:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LABELFILESEL"));
    labelDelim = new wxStaticText(Panel1, ID_LABELDELIM, _("Delimiter:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LABELDELIM"));
    labelTableName = new wxStaticText(Panel2, ID_LABELTABLENAME, _("Table:"),wxDefaultPosition, wxDefaultSize, 0, _T("ID_LABELTABLENAME"));


    // Controls
    fileButton = new wxButton(Panel1, ID_BUTTONKK, _("kk"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONKK"));
    buttonRun = new wxButton(this, ID_BUTTONRUN, _("Run"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONRUN"));
    TextCtrl1 = new wxTextCtrl(Panel1, ID_INPUTDELIM, _(","), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_INPUTDELIM"));
    fileTextInput = new wxTextCtrl(Panel1, ID_INPUTFILE, _("File etc"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_INPUTFILE"));
    tableNameTextInput = new wxTextCtrl(Panel2, ID_INPUTTABLENAME, _("Name"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_INPUTTABLENAME"));

    // Containers


    tabs->AddPage(Panel1, _("Files"), false);
    tabs->AddPage(Panel2, _("Connect"), false);




    // Add controls to sizers
    buttonSizer->Add(buttonRun, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    outerWrapper->Add(buttonSizer, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(labelFileSelect, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(fileTextInput, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(fileButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(labelDelim, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    dbWrapper->Add(labelTableName,1,wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    dbWrapper->Add(tableNameTextInput,1,wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);


    // Set properties



    // Set window properties
    Panel1->SetSizer(filesWrapper);
    filesWrapper->Fit(Panel1);
    filesWrapper->SetSizeHints(Panel1);

    Panel2->SetSizer(dbWrapper);
    dbWrapper->Fit(Panel2);
    dbWrapper->SetSizeHints(Panel2);

    SetSizer(outerWrapper);
    FileDialogue = new wxFileDialog(this, _("Select file"), _("."), wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    outerWrapper->Fit(this);
    outerWrapper->SetSizeHints(this);

    Connect(ID_TABS,wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,(wxObjectEventFunction)&MatrixDBDialog::OntabsPageChanged);
    Connect(ID_BUTTONKK,wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MatrixDBDialog::OnFileSelect));
    Connect(ID_BUTTONRUN,wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MatrixDBDialog::OnRun));

    //*)
}

MatrixDBDialog::~MatrixDBDialog()
{
    //(*Destroy(MatrixDBDialog)
    //*)
}

void MatrixDBDialog::OnFileSelect(wxCommandEvent& event)
{
    if (FileDialogue->ShowModal() == wxID_OK) // if the user click "Open" instead of "Cancel"
	{
		filePath = FileDialogue->GetPath();
        fileName = FileDialogue->GetFilename();
        fileTextInput->SetValue(filePath);
	}
}

void MatrixDBDialog::OnRun(wxCommandEvent& event)
{
    wxArrayString columns;
    ListBox1->GetStrings(columns);
    wxString name = fileTextInput->GetValue();
    wxString delimiter = TextCtrl1->GetValue();
    wxString tableName = tableNameTextInput->GetValue();

    FileProcessor* fp = new FileProcessor(name,delimiter,tableName);
    for(int i = 0; i<columns.GetCount();i++)
    {
        fp->addMysqlCols(columns.Item(i));
    }

    int error = fp->run();
    if(error>0)
        std::cout << "Error: " << error;
}

void MatrixDBDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void MatrixDBDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}



void MatrixDBDialog::OntabsPageChanged(wxNotebookEvent& event)
{
}
