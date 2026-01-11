////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/gluon/typedef/qobject.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <QObject>

namespace yq::tachyon {
    /*! \brief Adapter
    
        Simple adapter to bind QObject with the tachyon
    */
    template <SomeQObject QO, SomeTachyon TA>
    class XObject : public QO, public TA {
    public:
    
        // TODO... the thread push
    
        template <typename=void>
        requires std::is_constructible_v<QO>
        XObject()
        {
        }
        
        template <typename=void>
        requires std::is_constructible_v<QO,QObject*>
        XObject(QObject* parent) : QO(parent)
        {
        }
        
        virtual ~XObject()
        {
        }
        
    protected:
        virtual void deleteMe() const override
        {
            const_cast<XObject*>(this) -> deleteLater();
        }
    };
}
