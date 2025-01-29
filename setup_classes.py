import os


def create_class_skeleton(hpp_file):
    # Extract class name from file name
    class_name = os.path.splitext(os.path.basename(hpp_file))[0]

    with open(hpp_file, 'r') as f:
        content = f.read().strip()

    if len(content.replace('\n', '').strip()) > 0:
        return

    # Generate .hpp content
    hpp_content = f"""#ifndef {class_name.upper()}_HPP
# define {class_name.upper()}_HPP

class {class_name} {{
    public:
        // Canonical form
        {class_name}();
        {class_name}(const {class_name} &other);
        ~{class_name}();
        {class_name} &operator=(const {class_name} &other);

    private:
        // Add private members here
}};

#endif
"""

    # Generate .cpp content
    cpp_content = f"""#include "{class_name}.hpp"

{class_name}::{class_name}() {{
}}

{class_name}::{class_name}(const {class_name} &other) {{
    *this = other;
}}

{class_name}::~{class_name}() {{
}}

{class_name} &{class_name}::operator=(const {class_name} &other) {{
    if (this != &other) {{
        // Copy members here
    }}
    return *this;
}}
"""

    # Write files
    with open(hpp_file, 'w') as f:
        f.write(hpp_content)
    
    cpp_file = os.path.join('src', f'{class_name}.cpp')
    with open(cpp_file, 'w') as f:
        f.write(cpp_content)

def main():
    # Create src directory if it doesn't exist
    if not os.path.exists('src'):
        os.makedirs('src')
        return
    # Find all .hpp files
    for file in os.listdir('src'):
        if file.endswith('.hpp'):
            create_class_skeleton(os.path.join('src', file))

if __name__ == "__main__":
    main()
