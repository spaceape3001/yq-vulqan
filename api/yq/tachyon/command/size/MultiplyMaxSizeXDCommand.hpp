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
    class MultiplyMaxSizeˣDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSizeˣDCommand, SizeCommand)
    public:
        MultiplyMaxSizeˣDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δx() const { return m_δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMaxSizeˣDCommand(const MultiplyMaxSizeˣDCommand&, const Header&);
        MultiplyMaxSizeˣDCommand(const Header&);
        ~MultiplyMaxSizeˣDCommand();

    private:
        double  m_δx = 0.0;
        
        MultiplyMaxSizeˣDCommand(const MultiplyMaxSizeˣDCommand&) = delete;
        MultiplyMaxSizeˣDCommand(MultiplyMaxSizeˣDCommand&&) = delete;
        MultiplyMaxSizeˣDCommand& operator=(const MultiplyMaxSizeˣDCommand&) = delete;
        MultiplyMaxSizeˣDCommand& operator=(MultiplyMaxSizeˣDCommand&&) = delete;
    };
}
