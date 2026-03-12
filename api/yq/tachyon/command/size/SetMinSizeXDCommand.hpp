////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSizeˣDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSizeˣDCommand, SizeCommand)
    public:
        SetMinSizeˣDCommand(const Header&, double);
    
        static void init_meta();
        
        double  x() const { return m_x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSizeˣDCommand(const Header&);
        SetMinSizeˣDCommand(const SetMinSizeˣDCommand&, const Header&);
        ~SetMinSizeˣDCommand();

    private:
        double   m_x = 0.;
        
        SetMinSizeˣDCommand(const SetMinSizeˣDCommand&) = delete;
        SetMinSizeˣDCommand(SetMinSizeˣDCommand&&) = delete;
        SetMinSizeˣDCommand& operator=(const SetMinSizeˣDCommand&) = delete;
        SetMinSizeˣDCommand& operator=(SetMinSizeˣDCommand&&) = delete;
    };
}
