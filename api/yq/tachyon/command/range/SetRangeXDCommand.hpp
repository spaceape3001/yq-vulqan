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
    class SetRangeˣDCommand : public RangeCommand {
        YQ_OBJECT_DECLARE(SetRangeˣDCommand, RangeCommand)
    public:
        SetRangeˣDCommand(const Header&, const RangeD&);
    
        static void init_meta();
        
        const RangeD&  x_range() const { return m_xRange; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetRangeˣDCommand(const Header&);
        SetRangeˣDCommand(const SetRangeˣDCommand&, const Header&);
        ~SetRangeˣDCommand();

    private:
        RangeD   m_xRange = {};
        
        SetRangeˣDCommand(const SetRangeˣDCommand&) = delete;
        SetRangeˣDCommand(SetRangeˣDCommand&&) = delete;
        SetRangeˣDCommand& operator=(const SetRangeˣDCommand&) = delete;
        SetRangeˣDCommand& operator=(SetRangeˣDCommand&&) = delete;
    };
}
