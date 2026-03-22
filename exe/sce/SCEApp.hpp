////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/TEApp.hpp>

using namespace yq;
using namespace yq::tachyon;

class SCEApp : public TEApp {
public:
    SCEApp(int&,char* argv[], const AppCreateInfo &);
    ~SCEApp();

    static SCEApp*  app() { return s_app; }
    
private:
    static SCEApp*    s_app;

    mutable mutex_t                 m_mutex;
};
