////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddMaxSizeʷDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSizeʷDCommand, SizeCommand)
    public:
        AddMaxSizeʷDCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δw() const { return m_Δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSizeʷDCommand(const AddMaxSizeʷDCommand&, const Header&);
        AddMaxSizeʷDCommand(const Header&);
        ~AddMaxSizeʷDCommand();

    private:
        double  m_Δw = 0.0;
        
        AddMaxSizeʷDCommand(const AddMaxSizeʷDCommand&) = delete;
        AddMaxSizeʷDCommand(AddMaxSizeʷDCommand&&) = delete;
        AddMaxSizeʷDCommand& operator=(const AddMaxSizeʷDCommand&) = delete;
        AddMaxSizeʷDCommand& operator=(AddMaxSizeʷDCommand&&) = delete;
    };
}
