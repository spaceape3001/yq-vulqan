////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ModelSelectEvent.hpp"
#include <tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(ModelSelectEvent)

ModelSelectEvent::ModelSelectEvent(const Header& h, ModelID c) : EditorEvent(h), m_model(c)
{
}

ModelSelectEvent::ModelSelectEvent(const ModelSelectEvent&cp, const Header&h) : 
    EditorEvent(cp, h), m_model(cp.m_model)
{
}

ModelSelectEvent::~ModelSelectEvent()
{
}


PostCPtr    ModelSelectEvent::clone(rebind_k, const Header&h) const 
{
    return new ModelSelectEvent(*this, h);
}

void ModelSelectEvent::init_meta()
{
    auto w = writer<ModelSelectEvent>();
    w.description("Model Selection Event");
}

