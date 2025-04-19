import phonenumbers
import folium
from myphone import number, api_key
from phonenumbers import geocoder
from phonenumbers import carrier
from opencage.geocoder import OpenCageGeocode

pepnumber = phonenumbers.parse(number)
location = geocoder.description_for_number(pepnumber, "en")
print(location)

service_pro = phonenumbers.parse(number)
print(carrier.name_for_number(service_pro, "en"))

key = api_key

geocoder = OpenCageGeocode(key)
query = str(location)
results = geocoder.geocode(query)
# print(results)

lat = results[0]['geometry']['lat']
lng = results[0]['geometry']['lng']

print(lat, lng)

mymap = folium.Map(location=[lat, lng], zoom_start=10)
folium.Marker([lat, lng], popup=location).add_to(mymap)

mymap.save("Track Location/trackedLocation.html")