////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/HeightFieldCommand.hpp>
#include <yq/tachyon/typedef/height_field.hpp>

namespace yq::tachyon {
    class SetHeightFieldCommand : public HeightFieldCommand {
        YQ_OBJECT_DECLARE(SetHeightFieldCommand, HeightFieldCommand)
    public:
        SetHeightFieldCommand(const Header&, const HeightFieldCPtr&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const HeightFieldCPtr&     height_field() const { return m_heightField; }

    protected:
        SetHeightFieldCommand(const SetHeightFieldCommand&, const Header&);
        virtual ~SetHeightFieldCommand();
        
    private:
    
        HeightFieldCPtr            m_heightField;

        SetHeightFieldCommand(const SetHeightFieldCommand&) = delete;
        SetHeightFieldCommand(SetHeightFieldCommand&&) = delete;
        SetHeightFieldCommand& operator=(const SetHeightFieldCommand&) = delete;
        SetHeightFieldCommand& operator=(SetHeightFieldCommand&&) = delete;
    };
}
