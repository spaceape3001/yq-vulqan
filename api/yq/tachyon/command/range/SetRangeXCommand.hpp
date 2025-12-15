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
    class SetRangeˣCommand : public RangeCommand {
        YQ_OBJECT_DECLARE(SetRangeˣCommand, RangeCommand)
    public:
        SetRangeˣCommand(const Header&, const RangeD&);
    
        static void init_meta();
        
        const RangeD&  x_range() const { return m_xRange; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetRangeˣCommand(const Header&);
        SetRangeˣCommand(const SetRangeˣCommand&, const Header&);
        ~SetRangeˣCommand();

    private:
        RangeD   m_xRange = {};
        
        SetRangeˣCommand(const SetRangeˣCommand&) = delete;
        SetRangeˣCommand(SetRangeˣCommand&&) = delete;
        SetRangeˣCommand& operator=(const SetRangeˣCommand&) = delete;
        SetRangeˣCommand& operator=(SetRangeˣCommand&&) = delete;
    };
}
