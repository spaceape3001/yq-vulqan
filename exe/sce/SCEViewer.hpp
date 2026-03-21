////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tbb/spin_rw_mutex.h>
#include <yq/core/Ref.hpp>
#include <yq/vkqt/XTachyon.hpp>
#include <yq/assetvk/widget/CompositeWidget.hpp>

using namespace yq;
using namespace yq::tachyon;

class SCEViewer : public XTachyon<QObject, CompositeWidget> {
    YQ_TACHYON_DECLARE(SCEViewer, CompositeWidget)
    Q_OBJECT
public:

    SCEViewer(TypedID docId);
    ~SCEViewer();
    
    static void init_meta();
    
private:
    TypedID         m_docId;
};
