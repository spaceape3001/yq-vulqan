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
    class SetRangeʸCommand : public RangeCommand {
        YQ_OBJECT_DECLARE(SetRangeʸCommand, RangeCommand)
    public:
        SetRangeʸCommand(const Header&, const RangeD&);
    
        static void init_meta();
        
        const RangeD&  y_range() const { return m_yRange; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetRangeʸCommand(const Header&);
        SetRangeʸCommand(const SetRangeʸCommand&, const Header&);
        ~SetRangeʸCommand();

    private:
        RangeD   m_yRange = {};
        
        SetRangeʸCommand(const SetRangeʸCommand&) = delete;
        SetRangeʸCommand(SetRangeʸCommand&&) = delete;
        SetRangeʸCommand& operator=(const SetRangeʸCommand&) = delete;
        SetRangeʸCommand& operator=(SetRangeʸCommand&&) = delete;
    };
}
