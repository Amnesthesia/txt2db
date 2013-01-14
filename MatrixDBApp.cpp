/***************************************************************
 * Name:      MatrixDBApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Seminex ()
 * Created:   2012-12-01
 * Copyright: Seminex ()
 * License:
 **************************************************************/

#include "MatrixDBApp.h"

//(*AppHeaders
#include "MatrixDBMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(MatrixDBApp);

bool MatrixDBApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	MatrixDBDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
