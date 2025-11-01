////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSizeˣCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSizeˣCommand, SizeCommand)
    public:
        SetMinSizeˣCommand(const Header&, double);
    
        static void init_meta();
        
        double  x() const { return m_x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSizeˣCommand(const Header&);
        SetMinSizeˣCommand(const SetMinSizeˣCommand&, const Header&);
        ~SetMinSizeˣCommand();

    private:
        double   m_x = 0.;
        
        SetMinSizeˣCommand(const SetMinSizeˣCommand&) = delete;
        SetMinSizeˣCommand(SetMinSizeˣCommand&&) = delete;
        SetMinSizeˣCommand& operator=(const SetMinSizeˣCommand&) = delete;
        SetMinSizeˣCommand& operator=(SetMinSizeˣCommand&&) = delete;
    };
}
