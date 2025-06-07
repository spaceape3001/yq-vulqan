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
    class MultiplyMaxSizeʷCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSizeʷCommand, SizeCommand)
    public:
        MultiplyMaxSizeʷCommand(const Header&, double);
        
        static void init_info();
        
        double  δw() const { return m_δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMaxSizeʷCommand(const MultiplyMaxSizeʷCommand&, const Header&);
        MultiplyMaxSizeʷCommand(const Header&);
        ~MultiplyMaxSizeʷCommand();

    private:
        double  m_δw = 0.0;
        
        MultiplyMaxSizeʷCommand(const MultiplyMaxSizeʷCommand&) = delete;
        MultiplyMaxSizeʷCommand(MultiplyMaxSizeʷCommand&&) = delete;
        MultiplyMaxSizeʷCommand& operator=(const MultiplyMaxSizeʷCommand&) = delete;
        MultiplyMaxSizeʷCommand& operator=(MultiplyMaxSizeʷCommand&&) = delete;
    };
}
