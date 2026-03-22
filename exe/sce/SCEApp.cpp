////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SCEApp.hpp"

SCEApp* SCEApp::s_app   = nullptr;

SCEApp::SCEApp(int&argc, char* argv[], const AppCreateInfo& aci) : TEApp(argc, argv, aci)
{
    s_app   = this;

    for(int n=1;n<argc;++n){
        if(argv[n][0] == '-'){
            std::string_view    rem(argv[n]+2);
            switch(argv[n][1]){
            case 'R':
                m_respath.push_back(rem);
                break;
            case 'P':
                m_plugins.push_back(rem);
                break;
            }
        } else
            m_imports.push_back(argv[n]);
    }
}

SCEApp::~SCEApp()
{
    s_app = nullptr;
}


