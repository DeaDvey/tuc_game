from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver import Chrome, ChromeOptions
from selenium.common.exceptions import NoSuchElementException, StaleElementReferenceException
from selenium.webdriver.common.keys import Keys
from selenium.common.exceptions import NoSuchElementException
import time
import pathlib
import warnings

warnings.filterwarnings("ignore", category=DeprecationWarning)
opts = ChromeOptions()
opts.add_argument("--window-size=1500,1500")
opts.add_argument("--headless")
driver_path = (pathlib.Path(__file__).parent / 'chromedriver').resolve()
driver = webdriver.Chrome(str(driver_path), options=opts)
driver.implicitly_wait(5) # Just in case

driver.get("http://35.178.252.18/")

last_message = driver.find_element(By.CSS_SELECTOR, "text:last-of-type")
#print(last_message.text)

file = open('./talking/last-message.txt')

with open('./talking/last-message.txt', 'r') as reader:
    
    #print(reader.read())
    if reader.read() == last_message.text:
        exit

    elif reader.read() != last_message.text:
        with open('./talking/last-message.txt', 'w') as writer:
            print("\n\n" + last_message.text + "\n\n" + ">> ", end='')
            writer.write(last_message.text)

#print("got here and that")
file.close

driver.quit()
