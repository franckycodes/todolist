/***************************************************************
 * Name:      todolistMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    francky (franckywebdesign@gmail.com)
 * Created:   2021-07-29
 * Copyright: francky (franckycodes.com)
 * License:
 **************************************************************/

#include "todolistMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(todolistFrame)
#include <wx/intl.h>
#include <wx/string.h>
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

//(*IdInit(todolistFrame)
const long todolistFrame::idMenuQuit = wxNewId();
const long todolistFrame::idMenuAbout = wxNewId();
const long todolistFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(todolistFrame,wxFrame)
    //(*EventTable(todolistFrame)
    //*)
END_EVENT_TABLE()

todolistFrame::todolistFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(todolistFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    MenuBar1 = new wxMenuBar();

    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&todolistFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&todolistFrame::OnAbout);
    //*)

    //menus
    wxMenuItem *exportItem;
    exportItem=new wxMenuItem(Menu1, wxID_ANY, "Export", "Export to .txt or .csv",wxITEM_NORMAL);
    Menu1->Append(exportItem);
    //init app
    m_gbs=new wxGridBagSizer();
    m_gbsInput1=new wxGridBagSizer();

    m_lbl1=new wxStaticText(this,wxID_ANY,"New todo");
    m_todoBt=new wxButton(this, wxID_ANY, "create");
    m_resultLbl=new wxStaticText(this,wxID_ANY, "Todos");


    m_newTodoTxt=new wxTextCtrl(this,wxID_ANY);
    m_gbsInput1->Add(m_lbl1, wxGBPosition(0,0));
    m_gbsInput1->Add(m_newTodoTxt, wxGBPosition(0,1));
    m_gbsInput1->Add(m_todoBt, wxGBPosition(0,2));
    m_gbs->Add(m_gbsInput1, wxGBPosition(0,0));
    m_gbs->Add(m_resultLbl, wxGBPosition(1,0));


    this->SetMinClientSize(wxSize(800,600));
    this->SetMaxClientSize(wxSize(800,600));
    this->SetLabel("Francky todo");
    this->SetSizer(m_gbs);
    m_result="todo androany\n-------------------------------\n";
    //events
    Connect(m_todoBt->GetId(), wxEVT_BUTTON, (wxObjectEventFunction)& todolistFrame::OnNewTodoBtClicked);
}

todolistFrame::~todolistFrame()
{
    //(*Destroy(todolistFrame)
    //*)
}

void todolistFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void todolistFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void todolistFrame::OnNewTodoBtClicked(wxCommandEvent& event)
{
    m_result+=m_newTodoTxt->GetValue()+", \n";
    m_resultLbl->SetLabel(m_result);
}
