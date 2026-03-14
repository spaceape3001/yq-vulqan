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
    class SetRangeʸDCommand : public RangeCommand {
        YQ_OBJECT_DECLARE(SetRangeʸDCommand, RangeCommand)
    public:
        SetRangeʸDCommand(const Header&, const RangeD&);
    
        static void init_meta();
        
        const RangeD&  y_range() const { return m_yRange; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetRangeʸDCommand(const Header&);
        SetRangeʸDCommand(const SetRangeʸDCommand&, const Header&);
        ~SetRangeʸDCommand();

    private:
        RangeD   m_yRange = {};
        
        SetRangeʸDCommand(const SetRangeʸDCommand&) = delete;
        SetRangeʸDCommand(SetRangeʸDCommand&&) = delete;
        SetRangeʸDCommand& operator=(const SetRangeʸDCommand&) = delete;
        SetRangeʸDCommand& operator=(SetRangeʸDCommand&&) = delete;
    };
}
