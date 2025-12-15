////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/RangeCommand.hpp>
#include <yq/math/Range.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetRangeᶻCommand : public RangeCommand {
        YQ_OBJECT_DECLARE(SetRangeᶻCommand, RangeCommand)
    public:
        SetRangeᶻCommand(const Header&, const RangeD&);
    
        static void init_meta();
        
        const RangeD&  z_range() const { return m_zRange; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetRangeᶻCommand(const Header&);
        SetRangeᶻCommand(const SetRangeᶻCommand&, const Header&);
        ~SetRangeᶻCommand();

    private:
        RangeD   m_zRange = {};
        
        SetRangeᶻCommand(const SetRangeᶻCommand&) = delete;
        SetRangeᶻCommand(SetRangeᶻCommand&&) = delete;
        SetRangeᶻCommand& operator=(const SetRangeᶻCommand&) = delete;
        SetRangeᶻCommand& operator=(SetRangeᶻCommand&&) = delete;
    };
}
