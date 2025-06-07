////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyMinSizeʷCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSizeʷCommand, SizeCommand)
    public:
        MultiplyMinSizeʷCommand(const Header&, double);
        
        static void init_info();
        
        double  δw() const { return m_δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMinSizeʷCommand(const MultiplyMinSizeʷCommand&, const Header&);
        MultiplyMinSizeʷCommand(const Header&);
        ~MultiplyMinSizeʷCommand();

    private:
        double  m_δw = 0.0;
        
        MultiplyMinSizeʷCommand(const MultiplyMinSizeʷCommand&) = delete;
        MultiplyMinSizeʷCommand(MultiplyMinSizeʷCommand&&) = delete;
        MultiplyMinSizeʷCommand& operator=(const MultiplyMinSizeʷCommand&) = delete;
        MultiplyMinSizeʷCommand& operator=(MultiplyMinSizeʷCommand&&) = delete;
    };
}
