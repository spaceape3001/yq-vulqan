////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/vkqt/XWidget.hpp>
#include <QToolBox>

namespace yq::tachyon {
    class TEViewCtrl;
    
    struct TEViewCtrlBoxOptions {
        size_t      initial_count   = 4;
        size_t      maximum_count   = 8;
    };
    
    class TEViewCtrlBox : public XWidget<QToolBox,Tachyon> {
        YQ_TACHYON_DECLARE(TEViewCtrlBox, Tachyon)
        Q_OBJECT
    public:
    
        TEViewCtrlBox(QWidget* parent=nullptr);
        TEViewCtrlBox(const TEViewCtrlBoxOptions&, QWidget* parent=nullptr);
        ~TEViewCtrlBox();
        
        static void init_meta();
        
        Execution                   setup(const Context&) override;
    
    private:
        std::vector<TEViewCtrl*>    m_ctrls;
        TEViewCtrlBoxOptions        m_params;
    };
}
