////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSizeʷCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSizeʷCommand, SizeCommand)
    public:
        SetMinSizeʷCommand(const Header&, double);
    
        static void init_meta();
        
        double  w() const { return m_w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSizeʷCommand(const Header&);
        SetMinSizeʷCommand(const SetMinSizeʷCommand&, const Header&);
        ~SetMinSizeʷCommand();

    private:
        double   m_w = 0.;
        
        SetMinSizeʷCommand(const SetMinSizeʷCommand&) = delete;
        SetMinSizeʷCommand(SetMinSizeʷCommand&&) = delete;
        SetMinSizeʷCommand& operator=(const SetMinSizeʷCommand&) = delete;
        SetMinSizeʷCommand& operator=(SetMinSizeʷCommand&&) = delete;
    };
}
