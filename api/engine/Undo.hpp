////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq {
    namespace engine {
    
        class Undo {
        public:
       
            virtual void undo() {}
            virtual void redo() {}
            
            //! Allows undos to combine (ie, text and more text)
            virtual bool combine(Undo* next);
            
            std::string_view   label() const { return m_label; }
            
            virtual ~Undo();
            
        protected:
            std::string         m_label;
        };
    
    }
}
