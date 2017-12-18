# Install dependencies nessecary for LightSpeed to function
# In the future, we could use LightSpeed itself, but for now it has to be manual

# Install JSON for C++ in external
git clone https://github.com/nlohmann/json external/json
mv external/json/src/json.hpp external/json.hpp
rm -rf external/json
