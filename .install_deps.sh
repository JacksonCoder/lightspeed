# Install dependencies nessecary for LightSpeed to function
# In the future, we could use LightSpeed itself, but for now it has to be manual

# Install JSON for C++ in external
git clone https://github.com/nlohmann/json lightspeed/core/external/json
mv lightspeed/core/external/json/src/json.hpp lightspeed/core/external/json.hpp
rm -rf lightspeed/core/external/json

# Install GoogleTest

git clone https://github.com/google/googletest lightspeed/tests/external/googletest
