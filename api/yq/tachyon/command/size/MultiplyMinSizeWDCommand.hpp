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
    class MultiplyMinSizeʷDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSizeʷDCommand, SizeCommand)
    public:
        MultiplyMinSizeʷDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δw() const { return m_δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMinSizeʷDCommand(const MultiplyMinSizeʷDCommand&, const Header&);
        MultiplyMinSizeʷDCommand(const Header&);
        ~MultiplyMinSizeʷDCommand();

    private:
        double  m_δw = 0.0;
        
        MultiplyMinSizeʷDCommand(const MultiplyMinSizeʷDCommand&) = delete;
        MultiplyMinSizeʷDCommand(MultiplyMinSizeʷDCommand&&) = delete;
        MultiplyMinSizeʷDCommand& operator=(const MultiplyMinSizeʷDCommand&) = delete;
        MultiplyMinSizeʷDCommand& operator=(MultiplyMinSizeʷDCommand&&) = delete;
    };
}
