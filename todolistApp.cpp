/***************************************************************
 * Name:      todolistApp.cpp
 * Purpose:   Code for Application Class
 * Author:    francky (franckywebdesign@gmail.com)
 * Created:   2021-07-29
 * Copyright: francky (franckycodes.com)
 * License:
 **************************************************************/

#include "todolistApp.h"

//(*AppHeaders
#include "todolistMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(todolistApp);

bool todolistApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	todolistFrame* Frame = new todolistFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
