#include "stdafx.h"
#include "DialogAbout.h"

// For Utils::GetVersionInfo
#pragma comment(lib, "version.lib")

CDialogAbout::CDialogAbout( ) : CDialogEx( CDialogAbout::IDD )
{
}

BEGIN_MESSAGE_MAP( CDialogAbout, CDialogEx )
END_MESSAGE_MAP( )

void CDialogAbout::DoDataExchange( CDataExchange * pDX )
{
    CDialogEx::DoDataExchange( pDX );
}

BOOL CDialogAbout::OnInitDialog( )
{
    CDialogEx::OnInitDialog( );

    CString strTemp;
    strTemp.Format( _T( "Build Date: %s - %s" ), _T( __DATE__ ), _T( __TIME__ ) );
    SetDlgItemText( IDC_ABOUT_BUILD_DATE, strTemp );
    CString strReclassVersion = Utils::GetVersionInfo( _T( "FileVersion" ) );
    strTemp.Format( _T( "Version: %s" ), strReclassVersion.GetString( ) );
    SetDlgItemText( IDC_ABOUT_BUILD_VERSION, strTemp );
    CString authors;
    authors.LoadString( IDS_AUTHOR_STRING );
    SetDlgItemText( IDC_ABOUT_AUTHORS, authors );

    CString strLegalCopyright = Utils::GetVersionInfo( _T( "LegalCopyright" ) );
    strTemp.Format( _T(
        "The MIT License (MIT)\r\n\r\n"
        "%s %s\r\n\r\n"
        "Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files(the \"Software\"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and / or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:\r\n\r\n"
        "The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.\r\n\r\n"
        "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.\r\n"
    ), strLegalCopyright, authors );
    SetDlgItemText( IDC_ABOUT_LICENSE, strTemp );

    SetFocus( );

    return TRUE;
}
