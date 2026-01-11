////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/gluon/typedef/qwidget.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <QWidget>

namespace yq::tachyon {
    /*! \brief Adapter
    
        Simple adapter to bind QWidget with the tachyon
    */
    template <SomeQWidget QW, SomeTachyon TA>
    class XWidget : public QW, public TA {
    public:
    
        using xwidget_type = XWidget;
        using qwidget_type = QW;
        using tachyon_type = TA;
    
        XWidget(QWidget* parent=nullptr) : QW(parent)
        {
        }

        virtual ~XWidget()
        {
        }
        
    protected:
        virtual void deleteMe() const override
        {
            const_cast<XWidget*>(this) -> deleteLater();
        }
    };
}
