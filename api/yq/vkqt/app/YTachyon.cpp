////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/Thread.hpp>
#include "YTachyonMetaWriter.hpp"
#include <QThread>

YQ_TACHYON_IMPLEMENT(yq::tachyon::YTachyon)

namespace yq::tachyon {
    bool    qt_pushed(QObject& obj, ThreadID tid)
    {
        const Frame* frame   = Frame::current();
        if(!frame)
            return false;
        Thread* th = frame->object(tid);
        if(!th)
            return false;
        QThread*    qT  = dynamic_cast<QThread*>(th);
        if(!qT)
            return false;
        return obj.moveToThread(qT);
    }

    YTachyon::YTachyon()
    {
    }
    
    YTachyon::~YTachyon()
    {
    }

    void YTachyon::init_meta()
    {
        auto w = writer<YTachyon>();
        w.description("Qt/Tachyon hybrid base class");
        w.abstract();
    }
}

#include "moc_YTachyon.cpp"
