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
    class MultiplySizeʷDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplySizeʷDCommand, SizeCommand)
    public:
        MultiplySizeʷDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δw() const { return m_δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplySizeʷDCommand(const MultiplySizeʷDCommand&, const Header&);
        MultiplySizeʷDCommand(const Header&);
        ~MultiplySizeʷDCommand();

    private:
        double  m_δw = 0.0;
        
        MultiplySizeʷDCommand(const MultiplySizeʷDCommand&) = delete;
        MultiplySizeʷDCommand(MultiplySizeʷDCommand&&) = delete;
        MultiplySizeʷDCommand& operator=(const MultiplySizeʷDCommand&) = delete;
        MultiplySizeʷDCommand& operator=(MultiplySizeʷDCommand&&) = delete;
    };
}
