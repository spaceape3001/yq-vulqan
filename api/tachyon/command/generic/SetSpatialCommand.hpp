////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Command.hpp>
#include <tachyon/api/TypedID.hpp>

namespace yq::tachyon {
    class SetSpatialCommand : public Command {
        YQ_OBJECT_DECLARE(SetSpatialCommand, Command)
    public:
        SetSpatialCommand(const Header&, TypedID);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();
        
        TypedID spatial() const { return m_spatial; }

    protected:
        SetSpatialCommand(const SetSpatialCommand&, const Header&);
        virtual ~SetSpatialCommand();
        
    private:
    
        TypedID       m_spatial;

        SetSpatialCommand(const SetSpatialCommand&) = delete;
        SetSpatialCommand(SetSpatialCommand&&) = delete;
        SetSpatialCommand& operator=(const SetSpatialCommand&) = delete;
        SetSpatialCommand& operator=(SetSpatialCommand&&) = delete;
    };
}
