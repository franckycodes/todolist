/***************************************************************
 * Name:      todolistApp.h
 * Purpose:   Defines Application Class
 * Author:    francky (franckywebdesign@gmail.com)
 * Created:   2021-07-29
 * Copyright: francky (franckycodes.com)
 * License:
 **************************************************************/

#ifndef TODOLISTAPP_H
#define TODOLISTAPP_H

#include <wx/app.h>

class todolistApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // TODOLISTAPP_H
