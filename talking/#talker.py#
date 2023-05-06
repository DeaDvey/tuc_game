from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver import Chrome, ChromeOptions
from selenium.common.exceptions import NoSuchElementException, StaleElementReferenceException
from selenium.webdriver.common.keys import Keys
from selenium.common.exceptions import NoSuchElementException
import time
import xlsxwriter
import pathlib



opts = ChromeOptions()
opts.add_argument("--window-size=1500,1500")
opts.add_argument("--headless")
driver_path = (pathlib.Path(__file__).parent / 'chromedriver').resolve()
driver = webdriver.Chrome(str(driver_path), options=opts)
driver.implicitly_wait(5) # Just in case


