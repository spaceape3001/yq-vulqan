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
    class SetRangeᶻDCommand : public RangeCommand {
        YQ_OBJECT_DECLARE(SetRangeᶻDCommand, RangeCommand)
    public:
        SetRangeᶻDCommand(const Header&, const RangeD&);
    
        static void init_meta();
        
        const RangeD&  z_range() const { return m_zRange; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetRangeᶻDCommand(const Header&);
        SetRangeᶻDCommand(const SetRangeᶻDCommand&, const Header&);
        ~SetRangeᶻDCommand();

    private:
        RangeD   m_zRange = {};
        
        SetRangeᶻDCommand(const SetRangeᶻDCommand&) = delete;
        SetRangeᶻDCommand(SetRangeᶻDCommand&&) = delete;
        SetRangeᶻDCommand& operator=(const SetRangeᶻDCommand&) = delete;
        SetRangeᶻDCommand& operator=(SetRangeᶻDCommand&&) = delete;
    };
}
