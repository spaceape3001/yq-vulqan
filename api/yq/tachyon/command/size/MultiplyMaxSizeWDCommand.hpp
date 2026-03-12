////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyMaxSizeʷDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSizeʷDCommand, SizeCommand)
    public:
        MultiplyMaxSizeʷDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δw() const { return m_δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMaxSizeʷDCommand(const MultiplyMaxSizeʷDCommand&, const Header&);
        MultiplyMaxSizeʷDCommand(const Header&);
        ~MultiplyMaxSizeʷDCommand();

    private:
        double  m_δw = 0.0;
        
        MultiplyMaxSizeʷDCommand(const MultiplyMaxSizeʷDCommand&) = delete;
        MultiplyMaxSizeʷDCommand(MultiplyMaxSizeʷDCommand&&) = delete;
        MultiplyMaxSizeʷDCommand& operator=(const MultiplyMaxSizeʷDCommand&) = delete;
        MultiplyMaxSizeʷDCommand& operator=(MultiplyMaxSizeʷDCommand&&) = delete;
    };
}
