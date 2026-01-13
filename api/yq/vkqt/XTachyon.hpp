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
    bool     qt_pushed(QObject&, ThreadID);

    /*! \brief Adapter
    
        Simple adapter to bind QObject with the tachyon
    */
    template <SomeQObject QO, SomeTachyon TA>
    class XTachyon : public QO, public TA {
    public:
    
        // TODO... the thread push
    
        template <typename=void>
        requires std::is_constructible_v<QO>
        XTachyon()
        {
        }
        
        template <typename=void>
        requires std::is_constructible_v<QO,QObject*>
        XTachyon(QObject* parent) : QO(parent)
        {
        }
        
        virtual ~XTachyon()
        {
        }
        
        
        virtual void    owner(push_k, ThreadID tid) 
        {
            if(!qt_pushed(*this, tid))
                return;
            TA::owner(PUSH, tid);
        }

    protected:
        virtual void deleteMe() const override
        {
            const_cast<XTachyon*>(this) -> deleteLater();
        }
    };
}
