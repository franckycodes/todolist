/***************************************************************
 * Name:      todolistMain.h
 * Purpose:   Defines Application Frame
 * Author:    francky (franckywebdesign@gmail.com)
 * Created:   2021-07-29
 * Copyright: francky (franckycodes.com)
 * License:
 **************************************************************/

#ifndef TODOLISTMAIN_H
#define TODOLISTMAIN_H

//(*Headers(todolistFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)
#include <wx/gbsizer.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/string.h>
class todolistFrame: public wxFrame
{
    public:

        todolistFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~todolistFrame();

    private:
        wxGridBagSizer *m_gbs;
        wxGridBagSizer *m_gbsInput1;
        wxTextCtrl *m_newTodoTxt;
        wxStaticText *m_lbl1;
        wxStaticText *m_lbl2;
        wxStaticText *m_lbl3;
        wxStaticText *m_resultLbl;
        wxButton *m_todoBt;
        wxString m_result;
        //(*Handlers(todolistFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnNewTodoBtClicked(wxCommandEvent& event);

        //*)

        //(*Identifiers(todolistFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(todolistFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // TODOLISTMAIN_H
