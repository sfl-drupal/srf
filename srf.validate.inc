<?php

/**
 * Helper function to clean customized field label,
 * to print it in an error message
 * @param  string $srf_label Label to be cleaned
 */
function srf_clean_field_label($srf_label) {
  return str_replace(' *', '', strip_tags($srf_label));
}

/**
 * Helper function to print publication warning on a field.
 * @param  string $field_name  Field machine name
 * @param  string $field_label Field (instance) label
 */
function srf_print_field_warning($field_name, $field_label, $new_status) {
  form_set_error($field_name, t('Field <strong>@field_label</strong> is required to pass this content as: <strong>@new_status</strong>.', array('@field_label' => $field_label, '@new_status' => $new_status)));
}

/**
 * Helper function to check filling text_long fields.
 */
function srf_text_validate($element, &$form_state, $form, $new_status) {
  $field_name = $element['#field_name'];
  $field_language = field_language($form['#entity_type'], $form_state['node'], $field_name);
  $field_values = $form_state['values'][$field_name][$field_language];
  if (!$field_values[0]['value']) {
    $field_label = srf_clean_field_label($element['#title']);
    srf_print_field_warning($field_name, $field_label, $new_status);
  }
}

/**
 * Helper function to check filling text_long fields.
 */
function srf_text_long_validate($element, &$form_state, $form, $new_status) {
  $field_name = $element['#field_name'];
  $field_language = field_language($form['#entity_type'], $form_state['node'], $field_name);
  $field_values = $form_state['values'][$field_name][$field_language];
  if (!$field_values[0]['value']) {
    $field_label = srf_clean_field_label($element['#title']);
    srf_print_field_warning($field_name, $field_label, $new_status);
  }
}

/**
 * Helper function to check filling text_with_summary fields.
 */
function srf_text_with_summary_validate($element, &$form_state, $form, $new_status) {
  $field_name = $element['#field_name'];
  $field_language = field_language($form['#entity_type'], $form_state['node'], $field_name);
  $field_values = $form_state['values'][$field_name][$field_language];
  if (!$field_values[0]['value']) {
    $field_label = srf_clean_field_label($element['#title']);
    srf_print_field_warning($field_name, $field_label, $new_status);
  }
}

/**
 * Helper function to check filling entityreference fields.
 */
function srf_entityreference_validate($element, &$form_state, $form, $new_status) {
  $field_name = $element['target_id']['#field_name'];
  $field_language = field_language($form['#entity_type'], $form_state['node'], $field_name);
  $field_values = $form_state['values'][$field_name][$field_language];
  if (!$field_values[0]['target_id']) {
    $field_label = srf_clean_field_label($element['target_id']['#title']);
    srf_print_field_warning($field_name, $field_label, $new_status);
  }
}

/**
 * Helper function to check filling taxonomy_term_reference fields.
 */
function srf_taxonomy_term_reference_validate($element, &$form_state, $form, $new_status) {
  $field_name = $element['#field_name'];
  $field_language = field_language($form['#entity_type'], $form_state['node'], $field_name);
  $field_values = $form_state['values'][$field_name][$field_language];
  if (empty($field_values)) {
    $field_label = srf_clean_field_label($element['#title']);
    srf_print_field_warning($field_name, $field_label, $new_status);
  }
}

/**
 * Helper function to check filling image fields.
 *
 * For image field, we must pass the arguments with a default value as NULL
 * and then check if they are not null, because we want to call this validate
 * function only when form is submitted (but not when «Upload» button is clicked).
 */
function srf_image_validate($element, &$form_state = NULL, $form = NULL, $new_status = NULL) {

  if ($element && $form_state && $form && $new_status) {

    // If $element is directly the field
    if (isset($element['#field_name'])) {
      _srf_helper_image_validate($element, $form_state, $form, $new_status);
    }

    // It may be an array of fields, so we have to iterate
    else {
      foreach ($element as $delta => &$elem) {
        _srf_helper_image_validate($element[$delta], $form_state, $form, $new_status);
      }
    }
  }
}

function _srf_helper_image_validate(&$element, &$form_state, $form, $new_status) {
  $field_name = $element['#field_name'];
  $field_language = field_language($form['#entity_type'], $form_state['node'], $field_name);
  $field_values = $form_state['values'][$field_name][$field_language];
  if (!$field_values[0]['fid']) {
    $field_label = srf_clean_field_label($element['#title']);
    srf_print_field_warning($field_name, $field_label, $new_status);
  }
}

/**
 * Helper function to check filling file fields.
 *
 * Arguments are passed with a default value as NULL
 * for the same reason as image field.
 * @see srf_image_validate()
 */
function srf_file_validate($element, &$form_state = NULL, $form = NULL, $new_status = NULL) {

  // For the file, we must pass the arguments with a default value and check if
  // the value is set, because the call to the function validate is made when
  // the user try to upload it and in that moment, the form has not been submited.
  if ($element && $form_state && $form && $new_status) {
    foreach ($element as $id => &$elem) {
      if (!isset($elem['#field_name'])) {
        continue;
      }
      $field_name = $elem['#field_name'];
      $field_language = field_language($form['#entity_type'], $form_state['node'], $field_name);
      $field_values = $form_state['values'][$field_name][$field_language];
      if (!$field_values[0]['fid']) {
        $field_label = srf_clean_field_label($elem['#title']);
        srf_print_field_warning($field_name, $field_label, $new_status);
      }
    }
  }
}

/**
 * Helper function to check filling date fields.
 */
function srf_date_validate($element, &$form_state, $form, $new_status) {
  $field_name = $element['#field_name'];
  $field_language = field_language($form['#entity_type'], $form_state['node'], $field_name);
  $field_values = $form_state['values'][$field_name][$field_language];
  if (!$field_values[0]['value']) {
    $field_label = srf_clean_field_label($element['#title']);
    srf_print_field_warning($field_name, $field_label, $new_status);
  }
}

/**
 * Helper function to check filling datetime fields.
 */
function srf_datetime_validate($element, &$form_state, $form, $new_status) {
  $field_name = $element['#field_name'];
  $field_language = field_language($form['#entity_type'], $form_state['node'], $field_name);
  $field_values = $form_state['values'][$field_name][$field_language];
  // TODO: Check other elements of the array like value2, show_date, timezone, offset and offset2
  if (!$field_values[0]['value']) {
    $field_label = srf_clean_field_label($element['#title']);
    srf_print_field_warning($field_name, $field_label, $new_status);
  }
}

/**
 * Helper function to check filling image fields.
 */
function srf_link_field_validate($element, &$form_state, $form, $new_status) {
  $field_name = $element['#field_name'];
  $field_language = field_language($form['#entity_type'], $form_state['node'], $field_name);
  $field_values = $form_state['values'][$field_name][$field_language];
  if (!$field_values[0]['url']) {
    $field_label = srf_clean_field_label($element['#title']);
    srf_print_field_warning($field_name, $field_label, $new_status);
  }
}

/**
 * Helper function to check filling email fields.
 */
function srf_email_validate($element, &$form_state, $form, $new_status) {
  $field_name = $element['#field_name'];
  $field_language = field_language($form['#entity_type'], $form_state['node'], $field_name);
  $field_values = $form_state['values'][$field_name][$field_language];
  if (!$field_values[0]['email']) {
    $field_label = srf_clean_field_label($element['#title']);
    srf_print_field_warning($field_name, $field_label, $new_status);
  }
}
