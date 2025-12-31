////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/EditorEvent.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/model.hpp>

namespace yq::tachyon {

    class ModelSelectEvent : public EditorEvent {
        YQ_OBJECT_DECLARE(ModelSelectEvent, EditorEvent)
    public:
        ModelSelectEvent(const Header&, ModelID);
        ModelSelectEvent(const ModelSelectEvent&, const Header&);
        ~ModelSelectEvent();
        
        PostCPtr    clone(rebind_k, const Header&) const override;

        ModelID        model() const { return m_model; }
        static void init_meta();
    private:
        ModelID        m_model;
    };
}
