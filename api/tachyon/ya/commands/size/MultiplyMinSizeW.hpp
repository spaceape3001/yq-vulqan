////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyMinSizeʷ : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSizeʷ, SizeCommand)
    public:
        MultiplyMinSizeʷ(const Header&, double);
        
        static void init_info();
        
        double  δw() const { return m_δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMinSizeʷ(const MultiplyMinSizeʷ&, const Header&);
        MultiplyMinSizeʷ(const Header&);
        ~MultiplyMinSizeʷ();

    private:
        double  m_δw = 0.0;
        
        MultiplyMinSizeʷ(const MultiplyMinSizeʷ&) = delete;
        MultiplyMinSizeʷ(MultiplyMinSizeʷ&&) = delete;
        MultiplyMinSizeʷ& operator=(const MultiplyMinSizeʷ&) = delete;
        MultiplyMinSizeʷ& operator=(MultiplyMinSizeʷ&&) = delete;
    };
}
