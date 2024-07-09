from pywinauto import Application, Desktop
import time, requests

def Download_MIH():
    url = 'https://myiphide.com/download/MIH_setup.exe'
    destination = 'mih.exe'
    response = requests.get(url)

    if response.status_code == 200:
        with open(destination, 'wb') as f:
            f.write(response.content)
        print("File downloaded successfully.")
    else:
        print(f"Failed to download file. Status code: {response.status_code}")

def Setup(app:Application):
    next_button = app.top_window().child_window(title="&Next >", class_name="TNewButton")
    next_button.click()
    time.sleep(2)
    next_button = app.top_window().child_window(title="&Next >", class_name="TNewButton")
    next_button.click()
    time.sleep(2)
    next_button = app.top_window().child_window(title="&Next >", class_name="TNewButton")
    next_button.click()
    time.sleep(2)
    next_button = app.top_window().child_window(title="&Next >", class_name="TNewButton")
    next_button.click()
    time.sleep(2)
    next_button = app.top_window().child_window(title="&Install", class_name="TNewButton")
    next_button.click()
    time.sleep(5)
    next_button = app.top_window().child_window(title="&Finish", class_name="TNewButton")
    next_button.click()
    time.sleep(4)

def Login():
    time.sleep(5)
    # Connect to the application
    dlg = Desktop(backend="uia")["My IP Hide"]

    # Print control identifiers for debugging
    dlg.print_control_identifiers()

    # Write to the first field (assuming the first field is 'Custom2')
    field1 = dlg.child_window(control_type="Custom", found_index=2)
    field1.click_input()  # Click to focus
    field1.type_keys("bikojis578@bsidesmn.com")

    # Write to the second field (assuming the second field is 'Custom3')
    field2 = dlg.child_window(control_type="Custom", found_index=3)
    field2.click_input()  # Click to focus
    field2.type_keys("77nnaa")

    # Click the 'Login' button (assuming it is 'Custom4')
    login_button = dlg.child_window(control_type="Custom", found_index=4)
    login_button.click_input()

    time.sleep(3)
    # Click On OK button
    msg = dlg.child_window(control_type="Custom", found_index=3)
    msg.click_input()
    time.sleep(6)

def Window1():# fastest ip address
    dlg = Desktop(backend="uia")["Fastest IP Address"]
    button = dlg.child_window(control_type="Custom", found_index=2)
    button.click_input()
    

def Window2(): # are you want to buy pro version window
    dlg = Desktop(backend="uia")["Fastest IP Address"]
    button = dlg.child_window(control_type="Custom", found_index=4)
    button.click_input()

def ChooseButton():
    dlg = Desktop(backend="uia")["Choose An IP Address"]
    login_button = dlg.child_window(control_type="Custom", found_index=10)
    login_button.click_input()

def main():
    try:
        Download_MIH()
        # Start the application
        Application(backend='win32').start('mih.exe')
        time.sleep(4)
        app = Application(backend='win32').connect(title=u'Setup - My IP Hide', class_name='TMainForm')

        Setup(app)

        app = Application(backend='win32').connect(title=u'Login My IP Hide', class_name='QTool')

        Login()

        print("Started 'mih.exe' and clicked 'Next >' button successfully.")

        Window1()
        time.sleep(2)
        Window2()
        time.sleep(2)
        ChooseButton()

        try:
            app.top_window().print_control_identifiers()
        except Exception as e:
            print(f"Error printing control identifiers: {e}")

    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()
