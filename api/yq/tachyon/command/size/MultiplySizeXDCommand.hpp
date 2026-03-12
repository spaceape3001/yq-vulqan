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
    class MultiplySizeˣDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplySizeˣDCommand, SizeCommand)
    public:
        MultiplySizeˣDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δx() const { return m_δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplySizeˣDCommand(const MultiplySizeˣDCommand&, const Header&);
        MultiplySizeˣDCommand(const Header&);
        ~MultiplySizeˣDCommand();

    private:
        double  m_δx = 0.0;
        
        MultiplySizeˣDCommand(const MultiplySizeˣDCommand&) = delete;
        MultiplySizeˣDCommand(MultiplySizeˣDCommand&&) = delete;
        MultiplySizeˣDCommand& operator=(const MultiplySizeˣDCommand&) = delete;
        MultiplySizeˣDCommand& operator=(MultiplySizeˣDCommand&&) = delete;
    };
}
